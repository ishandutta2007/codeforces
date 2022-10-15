#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

struct PT{
        int x;
        int y;
        int i;
};

bool operator < (PT a,PT b){
        if(a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}

const int N=2000+7;
int n;
PT a[N];
string s;

ll get(int i,int j){
        return (ll)(a[i].x+a[j].x)*(a[i].y-a[j].y);
}

ll get(int i,int j,int k){
        return get(i,j)+get(j,k)+get(k,i);
}

int main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>a[i].x>>a[i].y;
                a[i].i=i;
        }
        cin>>s;
        for(int i=1;i<n;i++){
                if(a[i]<a[n]){
                        swap(a[i],a[n]);
                }
        }
        /// a[n] is the new minimum

        reverse(s.begin(),s.end());

        assert((int)s.size()==n-2);


        while(n>=3){
                cout<<a[n].i<<" ";
                assert(!s.empty());
                char ch=s.back();
                s.pop_back();
                assert(ch=='L'||ch=='R');
                int sol=n-1;
                if(ch=='R'){ /// or sol=='R'
                        for(int i=1;i<n-1;i++){
                                if(get(i,sol,n)>0) {
                                        sol=i;
                                }
                        }
                }else{
                        for(int i=1;i<n-1;i++){
                                if(get(i,sol,n)<0) {
                                        sol=i;
                                }
                        }
                }
                n--;
                swap(a[sol],a[n]);
        }
        assert(n==2);
        cout<<a[2].i<<" "<<a[1].i<<"\n";
        assert(s.empty());

        return 0;
}