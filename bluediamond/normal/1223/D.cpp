#include <bits/stdc++.h>

using namespace std;

const int N=(int)3e5+7;
int n,f[N],l[N],all;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int q;
        cin>>q;

        while(q--)
        {
                cin>>n;
                all=0;
                for(int i=1;i<=n;i++)
                        f[i]=l[i]=0;

                for(int i=1;i<=n;i++)
                {
                        int x;
                        cin>>x;
                        if(f[x]==0)
                        {
                                all++;
                                f[x]=i;
                        }
                        l[x]=i;
                }

                vector <int> nums;

                for(int x=1;x<=n;x++)
                        if(f[x])
                                nums.push_back(x);

                int i=0,j=-1,ans=1;
                while(i<(int)nums.size())
                {
                        if(j<i)
                                j=i;
                        while(j+1<(int)nums.size() && l[nums[j]]+1<=f[nums[j+1]])
                                j++;
                        ans=max(ans,j-i+1);
                        i=j+1;
                }
                cout<<all-ans<<"\n";

        }


        return 0;
}