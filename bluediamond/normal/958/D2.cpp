#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home=1;

const ld eps=1e-10;
int d;

bool are_eq(vector<ld> a, vector<ld> b){
        assert((int)a.size()==d*d);
        assert((int)b.size()==d*d);
        for(int i=0;i<d*d;i++){
                if(fabs(a[i]-b[i])>eps){
                        return 0;
                }
        }
        return 1;
}


void print(vector<vector<ld>> a){
        for(auto&v:a){
                for(auto&x:v){
                        cout<<fixed<<setprecision(6)<<x<<" ";
                }
                cout<<"\n";
        }
        cout<<"############\n";

}

vector<ld> normalize(vector<vector<ld>> a){
        while((int)a.size()<d){
                a.push_back(vector<ld> (d,0));
        }
        assert((int)a.size()==d);
        sort(a.begin(),a.end(),[&](vector<ld> x,vector<ld> y){
        for(int p=0;p<d;p++) {
                if(fabs(x[p]-y[p])<eps)continue;
                return x[p]<y[p];
        }
        return 0<0;
        });
        for(int i=0;i<d;i++){
              assert((int)a[i].size()==d);
        }
        vector<bool> vi(d,0),vj(d,0);
        vector<ld> coef(d,0);
        for(int step=0;step<d;step++){
                int r=-1,c=-1;
                for(int i=0;i<d;i++){
                        if(!vi[i]){
                                for(int j=0;j<d;j++){
                                        if(!vj[j]&&fabs(a[i][j])>eps){
                                                if(r==-1){
                                                        r=i;
                                                        c=j;
                                                }else{

                                                        /**if(abs(a[i][j])>abs(a[r][c])){
                                                                r=i;
                                                                c=j;
                                                        }**/
                                                }
                                        }
                                }
                        }
                }


                if(r==-1||c==-1){
                        continue;
                }
                vi[r]=1;
                vj[c]=1;
                assert(fabs(a[r][c])>eps);

                {
                        ld value=a[r][c];
                        for(int j=0;j<d;j++){
                                a[r][j]/=value;
                        }
                }
                for(int i=0;i<d;i++){
                        if(i!=r&&abs(a[i][c])>eps){
                                ld coef=a[i][c]/a[r][c];
                                for(int j=0;j<d;j++){
                                        a[i][j]-=coef*a[r][j];
                                }
                        }
                }
        }
        for(int i=0;i<d;i++){
                for(auto&x:a[i]){
                        if(fabs(x)>eps){
                                ld dv=x;
                                for(auto&y:a[i]){
                                        y/=dv;
                                }
                                break;
                        }
                }
        }

        vector<ld> all(d*d);

        sort(a.begin(),a.end(),[&](vector<ld> x,vector<ld> y){
        for(int p=0;p<d;p++) {
                if(fabs(x[p]-y[p])<eps)continue;
                return x[p]<y[p];
        }
        return 0<0;
        });
        for(int i=0;i<d;i++){
                for(int j=0;j<d;j++){
                        all[i*d+j]=a[i][j];
                }
        }

        if(0){
                for(auto&v:a){
                        for(auto&x:v){
                                cout<<fixed<<setprecision(6)<<x<<" ";
                        }
                        cout<<"\n";
                }
                cout<<"############\n";
        }
        return all;
}

signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int n;
        cin>>n>>d;
        bool ok=0;
        vector<vector<ld>> all(n);
        vector<vector<vector<ld>>> init(n);
        for(int i=0;i<n;i++){
                int cnt;
                cin>>cnt;
                vector<vector<ld>> a(cnt,vector<ld>(d));
                int ff=0;
                for(auto&v:a){
                        for(auto&x:v){
                                cin>>x;
                                if(i==0&&ff==0){
                                        ok=(x==22);
                                }
                                ff++;
                        }
                }
                init[i]=a;
                all[i]=normalize(a);
                if(0&&i>=9){
                        cout<<cnt<<"\n";
                        for(auto&v:a){
                                for(auto&x:v){
                                        cout<<x<<" ";
                                }
                                cout<<"\n";
                        }
                }
        }
        vector<int> inds(n);
        iota(inds.begin(),inds.end(),0);
        sort(inds.begin(),inds.end(),[&](int i,int j){
        for(int p=0;p<d*d;p++) {
                if(fabs(all[i][p]-all[j][p])<eps)continue;
                return all[i][p]<all[j][p];
        }
        return 0<0;
        });


        vector<int> coefs(n);
        coefs[inds[0]]=0;
        for(int i=1;i<n;i++){
                if(are_eq(all[inds[i-1]],all[inds[i]])){
                        coefs[inds[i]]=coefs[inds[i-1]];
                }else{
                        coefs[inds[i]]=1+coefs[inds[i-1]];
                }
        }
        ok=0;
        map<int,int>lol;
        for(auto&x:coefs){
                if(!lol.count(x)){
                        int s=(int)lol.size()+1;
                        lol[x]=s;
                }
        }
        int ind=0;
        for(auto&x:coefs){
                if(n==10000&&d==4&&ok){
                        if(lol[x]==1791 ||lol[x]==4950){
                                print(init[ind]);
                        }
                }
                ind++;
        }
        for(auto&x:coefs){
                cout<<lol[x]<<" ";
        }
        cout<<"\n";
}