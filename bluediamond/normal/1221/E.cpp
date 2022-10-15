#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

int a,b;

int type(int x){
        if(x<b) return 0;
        if(x<a) return 1;
        if(x<2*b) return 2;
        if(x>=2*b) return 3;

        assert(0);
}

int cnt[4];

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0);
        }


        int t;
        cin>>t;
        while(t--){
                string s;
                cin>>a>>b>>s;
                int n=(int)s.size();
                vector<int> v;
                int l=0;
                while(l<n){
                        if(s[l]=='X'){
                                l++;
                                continue;
                        }
                        int r=l;
                        while(r+1<n&&s[r+1]==s[r]) r++;
                        v.push_back(r-l+1);
                        l=r+1;
                }
                cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;

                for(auto&l:v){
                        cnt[type(l)]++;
                }

                bool wn=0;
                /// YNY SEBI

                for(auto&l:v){
                        for(int i=0;i<=l-a;i++){
                                int l1=i,l2=l-i-a;
                                cnt[type(l)]--;
                                if(l1) cnt[type(l1)]++;
                                if(l2) cnt[type(l2)]++;


                                if(cnt[1]==0&&cnt[3]==0){
                                        if(cnt[2]%2==0){
                                                wn=1;
                                        }
                                }

                                cnt[type(l)]++;
                                if(l1) cnt[type(l1)]--;
                                if(l2) cnt[type(l2)]--;
                        }
                }


                if(wn){
                        cout<<"YES\n";
                }else{
                        cout<<"NO\n";
                }
                continue;

                for(auto&x:v){
                        cout<<x<<" ";
                }
                cout<<"\n";
        }

        return 0;
}