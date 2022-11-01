#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tl,tr;
    cin >> tl >> tr;
    array<int,2> one={tl,tr};
    cin >> tl >> tr;
    array<int,2> two={tl,tr};
    array<int,2> st={0,0};
    if(one[0]==1&&one[1]==(1<<30)-1) st[0]=2;
    if(two[0]==1&&two[1]==(1<<30)-1) st[1]=2;
    int res=0;
    auto upd=[&](int a){res=max(res,a);};
    for(int i=30;i>=1;i--)
    {
        int sz=(1<<i)-1;
        int mid=(1<<(i-1));
        if(st[1]>st[0])
        {
            swap(one,two);
            swap(st[0],st[1]);
        }
        if(st[1]==3) break;
        if(st[1]==2)
        {
            if(st[0]==0) upd(one[1]-one[0]+1);
            else if(st[0]==1) upd(max(one[0],one[1]));
            else if(st[0]==2) upd(sz);
            break;
        }
        auto gen=[&](array<int,2> a,int s)->vector<array<int,2>>
        {
            if(s==0) return {a};
            else return {array<int,2>{1,a[0]},array<int,2>{sz-a[1]+1,sz}};
        };
        for(auto [l1,r1]:gen(one,st[0]))
        {
            if(!(l1<=mid&&mid<=r1)) continue;
            for(auto [l2,r2]:gen(two,st[1]))
            {
                if(!(l2<=mid&&mid<=r2)) continue;
                upd(min(r1,r2)-max(l1,l2)+1);
            }
        }
        auto mv=[&](array<int,2> &a,int &s)
        {
            if(s==0)
            {
                if((a[0]==1&&a[1]>=mid-1)||(a[0]<=mid+1&&a[1]==sz)) s=2;
                else if(a[0]<mid&&a[1]>mid)
                {
                    a={a[1]-mid,mid-a[0]};
                    s=1;
                }
                else if(a[0]==mid&&a[1]==mid) s=3;
                else
                {
                    if(a[0]==mid) a[0]++;
                    if(a[1]==mid) a[1]--;
                    if(a[0]>mid)
                    {
                        a[0]-=mid;
                        a[1]-=mid;
                    }
                }
            }
            else if(s==1)
            {
                if(max(a[0],a[1])>=mid-1) s=2;
            }
        };
        if(i>1)
        {
            mv(one,st[0]);
            mv(two,st[1]);
        }
    }
    cout << res << "\n";
    return 0;
}