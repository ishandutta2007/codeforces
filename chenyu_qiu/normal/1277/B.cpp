#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void work()
{
    map<int,int>m;
    set<int>s;
    int n;
    scanf("%d",&n);
    int maxx=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        int cnt=0;
        while(a%2==0){
            cnt++;
            a/=2;
        }
        if(cnt>=1){
            m[a]=max(m[a],cnt);
            s.insert(a);
        }
    }
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        ans+=m[*it];
    }
    printf("%d\n",ans);
 
}
int main()
{
    int T;
    scanf("%d",&T);
    //T=1;
    while(T--){
        work();
    }
}