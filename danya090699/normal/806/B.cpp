#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, inf=1e9+8;
    cin>>n;
    int ar[n][5], sol[5];
    for(int a=0; a<n; a++) for(int b=0; b<5; b++) cin>>ar[a][b];
    for(int a=0; a<5; a++) sol[a]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<5; b++) if(ar[a][b]!=-1) sol[b]++;
    }
    vector <int> qq;
    qq.push_back(0);
    for(int a=0; a<5; a++)
    {
        if(sol[a]!=0)
        {
            //cout<<a<<" ";
            int cu=-1;
            for(int b=1; b<=5; b++)
            {
                if(n<sol[a]*(1<<b))
                {
                    cu=b;
                    break;
                }
            }
            if(cu==-1) cu=6;
            //cout<<cu<<" ";
            for(int b=cu-1; b>0; b--)
            {
                int l=-1, r=inf;
                while(r-l>1)
                {
                    int mid=(l+r)/2;
                    if((n+mid)<(1<<b)*(sol[a]+mid)) r=mid;
                    else l=mid;
                }
                qq.push_back(r);
            }
            //cout<<cu<<" ";
            for(int b=cu+1; b<=6; b++)
            {
                //cout<<b<<" ";
                int l=-1, r=inf;
                while(r-l>1)
                {
                    int mid=(l+r)/2;
                    if((n+mid)>=(1<<(b-1))*sol[a]) r=mid;
                    else l=mid;
                }
                qq.push_back(r);
            }
            //cout<<cu<<" ";
        }
    }
    sort(qq.begin(), qq.end());
    int ans=-1;
    for(int a=0; a<qq.size(); a++)
    {
        int mid=qq[a], vp=0, pp=0;
        //cout<<mid<<" ";
        for(int b=0; b<5; b++)
        {
            int vt=ar[0][b], pt=ar[1][b];
            //if(mid==2) cout<<vt<<" "<<pt<<"\n";
            if(ar[0][b]==-1) vt=1000;
            if(ar[1][b]==-1) pt=1000;
            int nsol=sol[b];
            if(vt>pt and vt!=1000) nsol+=mid;
            int cu=-1;
            for(int c=1; c<=5; c++)
            {
                if(n+mid<nsol*(1<<c))
                {
                    cu=500*c;
                    break;
                }
            }
            //cout<<cu<<" ";
            if(cu==-1) cu=3000;
            //if(mid==1) cout<<nsol<<" "<<cu<<"\n";
            if(vt!=1000) vp+=cu-vt*(cu/250);
            if(pt!=1000) pp+=cu-pt*(cu/250);
        }
        if(vp>pp)
        {
            ans=mid;
            break;
        }
    }
    cout<<ans;
    //ksgbfdhj
}