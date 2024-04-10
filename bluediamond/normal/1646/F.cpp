#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;

void print(vector<vector<int>> f){
        for(auto&v:f){
                for(auto&x:v){
                        cout<<x<<" ";
                }
                cout<<"\n";
        }
        cout<<"-----------\n";
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
        cin>>n;
        vector<vector<int>> f(n,vector<int>(n,0));
/**
        function<void()>print=[&](){
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                for(int k=1;k<=f[i][j];k++){
                                        cout<<j<<" ";
                                }
                        }
                        cout<<"\n";
                }
                cout<<"---------\n";
        };
**/
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        int kol;
                        cin>>kol;
                        kol--;
                        f[i][kol]++;
                }
        }
        vector<vector<int>> sol;
        while(1){
                vector<int> is_eq(n,1);
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                is_eq[i]&=(f[i][j]==1);
                        }
                }
                if(*min_element(is_eq.begin(),is_eq.end())==1){

                        break;
                }
                vector<int> push(n,-1);
                for(int i=0;i<n;i++){
                        int j=(i+1)%n;
                        if(!is_eq[i]){
                                push[i]=0;
                                while(f[i][push[i]]<2) push[i]++;
                        }
                }
                for(int i=0;i<n;i++){
                        int j=(i+n-1)%n;
                        if(is_eq[i]){
                                push[i]=push[j];
                        }
                }
                for(int i=0;i<n;i++){
                        int j=(i+n-1)%n;
                        if(is_eq[i]){
                                push[i]=push[j];
                        }
                }
                assert(*min_element(push.begin(),push.end())!=-1);
                sol.push_back(push);
                for(int i=0;i<n;i++){
                        assert(f[i][push[i]]>=1);
                }
                for(int i=0;i<n;i++){
                        f[i][push[i]]--;
                        f[(i+1)%n][push[i]]++;
                }
        }
        if(!((int)sol.size()<=n*(n-1)/2)){
                cout<<(int)sol.size()<<" vs "<<n*(n-1)/2<<"\n";
                return 0;
        }

        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        assert(f[i][j]==1);
                }
        }
        for(int l=1;l<n;l++){
                for(int s=1;s<=l;s++){
                        vector<int> push(n,0);
                        for(int i=0;i<n;i++){
                                push[i]=(i-l+n)%n;
                        }
                        sol.push_back(push);
                        for(int i=0;i<n;i++){
                                assert(f[i][push[i]]>=1);
                        }
                        for(int i=0;i<n;i++){
                                f[i][push[i]]--;
                                f[(i+1)%n][push[i]]++;
                        }
                }
        }

        for(int i=0;i<n;i++){
                assert(f[i][i]==n);
        }
        cout<<(int)sol.size()<<"\n";
        for(auto&v:sol){
                for(auto&x:v){
                        cout<<x+1<<" ";
                }
                cout<<"\n";
        }
}