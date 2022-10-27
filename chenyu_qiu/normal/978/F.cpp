#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2*1e5+10;
struct node {
    int id;
    int val;
}b[MAXN],num[MAXN];
bool cmp(node x,node y){
    return x.val>y.val;
}
bool cmp1(node x,node y){
    return x.id<y.id;
}
int main(){
   int n,k,x,y;
   cin>>n>>k;
   for(int i=0;i<n;i++) cin>>b[i].val,b[i].id=i;
   sort(b,b+n,cmp);
   for(int i=0;i<n;i++) {
       int l=i,r=n-1;
       while(l<=r){
           int mid=(l+r)/2;
           if(b[mid].val<b[i].val) r=mid-1;
           else l=mid+1;
       }
       num[i].val=n-l;
       num[i].id=b[i].id;
   }
   sort(num,num+n,cmp1);
   sort(b,b+n,cmp1);
   while(k--){
       cin>>x>>y;
       if(b[x-1].val>b[y-1].val) num[x-1].val-=1;
       else if(b[x-1].val<b[y-1].val) num[y-1].val-=1;
   }
   for(int i=0;i<n;i++) cout<<num[i].val<<" ";
   cout<<endl;
}