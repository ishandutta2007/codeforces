#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, a[100005], d, k, used[1000005], in[1000005], pd;
vector <int> ans;

int32_t main()
{
    pd=-1;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    d=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            if(used[a[i]]==d)
            {
                cout << -1;
                return 0;
            }
            k++;
            used[a[i]]=d;
            in[a[i]]=d;
        }
        else
        {
            if(in[-a[i]]==d)
            {
                in[-a[i]]=0;
                k--;
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
        if(k==0)
            {
                d++;
                ans.push_back(i-pd);
                pd=i;
            }
    }
    if(k==0)
    {
        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << ' ';
    }
    else cout << -1;
}