#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        for(int i=1;i<=w;i++)
        {
            if(i%2 == 1 && i != w-1) cout << "1";
            else if(i == w) cout << "1";
            else cout << "0";
        }
        cout << "\n";
        for(int i=2;i<h;i++)
        {
            if(i%2 == 1 && i != h-1)
            {
                cout << "1";
                for(int j=2;j<w;j++) cout << "0";
                cout << "1\n";
            }
            else
            {
                for(int j=1;j<=w;j++) cout << "0";
                cout << "\n";
            }
        }
        for(int i=1;i<=w;i++)
        {
            if(i%2 == 1 && i != w-1) cout << "1";
            else if(i == w) cout << "1";
            else cout << "0";
        }
        cout << "\n\n";
    }
}