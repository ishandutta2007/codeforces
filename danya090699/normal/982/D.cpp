#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, be=0, k;
    cin>>n;
    pair <int, int> ar[n];
    int l[n], q[n+1];
    set <int> se;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a].first;
        ar[a].second=a;
        l[a]=0, q[a+1]=0;
    }
    sort(ar, ar+n);
    int yk=0;
    while(yk<n)
    {
        int cu=ar[yk].first;
        while(yk<n)
        {
            if(ar[yk].first==cu)
            {
                int p=ar[yk].second;
                int lq=0, rq=0;
                if(p>0) lq=l[p-1];
                if(p+1<n) rq=l[p+1];
                if(lq)
                {
                    q[lq]--;
                    if(q[lq]==0) se.erase(lq);
                }
                if(rq)
                {
                    q[rq]--;
                    if(q[rq]==0) se.erase(rq);
                }
                int qq=lq+1+rq;
                l[p-lq]=qq, l[p+rq]=qq;
                if(q[qq]==0) se.insert(qq);
                q[qq]++;

                yk++;
            }
            else break;
        }
        if(se.size()==1)
        {
            int qq=*se.begin();
            if(q[qq]>be)
            {
                be=q[qq], k=cu+1;
            }
        }
    }
    cout<<k;
}