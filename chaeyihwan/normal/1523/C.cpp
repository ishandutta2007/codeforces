#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[1002];

void print(vector<int> v)
{
    int s = v.size();
    for(int i=0;i<s-1;i++)
    {
        cout << v[i] << ".";
    }
    cout << v[s-1] << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            int s = v.size();
            if(a[i] == 1)
            {
                v.push_back(1);
                print(v);
                continue;
            }
            else
            {
                for(int j=s-1;j>=0;j--)
                {
                    if(v[j] == a[i] - 1)
                    {
                        v[j]++;
                        break;
                    }
                    v.pop_back();
                }
                print(v);
            }
        }
    }
}