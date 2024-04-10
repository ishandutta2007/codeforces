#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
typedef pair<int,int> pii;
const int inf=(int)1e9;
#define mk make_pair
const int N=500005;

void init()
{

}

int cl,ce,l[N],e[N],n,v,m,q;
void solve()
{
    scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
    for(int i=1;i<=cl;i++) scanf("%d",&l[i]);
    for(int i=1;i<=ce;i++) scanf("%d",&e[i]);
    sort(l+1,l+cl+1); sort(e+1,e+ce+1);
    scanf("%d",&q);
    while(q--)
    {
        int sx,sy,ex,ey;
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        if(sy>ey) swap(sy,ey);
        if(sx>ex) swap(sx,ex);
        int up=0,h=ex-sx;
        if(sx!=ex)
        {
            up=inf;
            int posl1=0,posl2=0,pose1=0,pose2=0;
            if(cl) posl1=lower_bound(l+1,l+cl+1,sy)-l;
            if(cl) posl2=lower_bound(l+1,l+cl+1,sy)-l-1;
            if(ce) pose1=lower_bound(e+1,e+ce+1,sy)-e;
            if(ce) pose2=lower_bound(e+1,e+ce+1,sy)-e-1;
            if(posl1==m+1) posl1=0; if(pose1==m+1) pose1=0;
            posl1=l[posl1]; posl2=l[posl2];
            pose1=e[pose1]; pose2=e[pose2];
            if(posl1) up=min(max(0,posl1-ey)*2+h,up);
            //cout<<up<<endl;
            if(posl2) up=min((sy-posl2)*2+h,up);
            //cout<<up<<" "<<endl;
            if(pose1) up=min(max(0,pose1-ey)*2+(h+v-1)/v,up);
            //cout<<up<<" "<<pose1<<endl;
            if(pose2) up=min((sy-pose2)*2+(h+v-1)/v,up);
            //cout<<up<<" "<<pose2<<endl;
        }
        printf("%d\n",up+ey-sy);
        //cout<<endl;
    }
}

signed main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}