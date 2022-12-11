#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,m,s1[N],tp1,s2[N],tp2;LL a[N];
struct node{int x,y;LL z;};
vector<node>ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),a[y]+=z,a[x]-=z;
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            while(tp1){
                if(a[i]+a[s1[tp1]]>=0)a[i]+=a[s1[tp1]],ans.push_back((node){s1[tp1],i,-a[s1[tp1]]}),tp1--;
                else{a[s1[tp1]]+=a[i];ans.push_back((node){s1[tp1],i,a[i]});a[i]=0;break;}
                if(!a[i])break;
            }
            if(a[i])s2[++tp2]=i;
        }
        if(a[i]<0){
            while(tp2){ 
                if(a[i]+a[s2[tp2]]<=0)a[i]+=a[s2[tp2]],ans.push_back((node){i,s2[tp2],a[s2[tp2]]}),tp2--;
                else{a[s2[tp2]]+=a[i];ans.push_back((node){i,s2[tp2],-a[i]});a[i]=0;break;}
                if(!a[i])break;
            }
            if(a[i])s1[++tp1]=i;
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)printf("%d %d ",ans[i].x,ans[i].y),cout<<ans[i].z<<endl;
    return 0;
}