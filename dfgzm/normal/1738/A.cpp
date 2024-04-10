#include<bits/stdc++.h>
#define ll long long
#define outY puts("YES")
#define outN puts("NO")
using namespace std;
const int maxn=100010;
int i,j,k,n,m,T,a[maxn];
vector<int>V1,V2;
int main(){
    cin>>T;
    while(T--){
        V1.clear();V2.clear();
        cin>>n;
        ll Ans=0;int Max=1e9+5,Max2=1e9+5;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(!a[i])V1.push_back(x);
            else V2.push_back(x);
        }
        sort(V1.begin(),V1.end());
        sort(V2.begin(),V2.end());
        if(V1.size()==V2.size())Ans-=min(V1[0],V2[0]);
        for(int i=0;i<V1.size();i++)
            if(V1.size()-i>V2.size())Ans+=V1[i];
            else Ans+=V1[i]*2;
        for(int i=0;i<V2.size();i++)
            if(V2.size()-i>V1.size())Ans+=V2[i];
            else Ans+=V2[i]*2;
        cout<<Ans<<endl;
    }
}