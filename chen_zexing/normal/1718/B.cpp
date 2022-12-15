#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[105];
long long p[105];
map <vector<int>,int> mp[105];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,step=1;
        long long s=1;
        p[1]=1;
        cin>>n;
        long long tot=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),tot+=a[i];
        vector <int> v;
        v.push_back(0);
        for(int i=1;i<=n;i++) v.push_back(a[i]);
        while(s<tot){
            step++,p[step]=p[step-1]+p[step-2];
            s+=p[step];
        }
        if(s!=tot){
            puts("NO");
            continue;
        }
        for(int i=0;i<=step;i++) mp[i].clear();
        mp[step][v]=1;
        int fl=1;
        for(int i=step;i;i--){
            if(!mp[i].size()){
                fl=0;
                break;
            }
            //cout<<i<<endl;
            for(auto temp:mp[i]){
                //for(int j=0;j<temp.first.size();j++) cout<<temp.first[j]<<" ";puts("");
                for(int j=temp.first.size()-1;j;j--){
                    if(j==temp.first[0]||temp.first[j]<p[i]) continue;
                    vector <int> nxt;
                    nxt=temp.first,nxt[j]-=p[i],nxt[0]=j;
                    if(!mp[i-1][nxt]) mp[i-1][nxt]=1;
                }
            }
        }
        puts(fl&&mp[0].size()?"YES":"NO");
    }
    return 0;
}