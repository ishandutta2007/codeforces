#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v={"10010","11020","20011","21012","11011","21021","22022","12021","11011","12012","10120","11130","20121","21122","11121","21131","22132","12131","11121","12122","10221","11231","12113","20222","21223","11222"};
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        for(int j=0;j<5;j++)
        {
            int a;
            cin >> a;
            s+=(a+'0');
        }
        for(int j=0;j<26;j++)
        {
            if(s==v[j])
            {
                cout << char(j+'a');
                break;
            }
        }
    }
    cout << "\n";
    return 0;
}