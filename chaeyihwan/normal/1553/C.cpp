#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string w; cin >> w;
        string l = w;
        for(int i=0;i<10;i++)
        {
            if(w[i] == '?')
            {
                w[i] = '0' + i%2;
                l[i] = '0' + (i+1)%2;
            }
        }

        int ans1 = 11, ans2 = 11, cnt1 = 0, cnt2 = 0;
        for(int i=0;i<5;i++)
        {
            if(w[i*2] == '1') cnt1--;
            if(cnt1 >= 5 - i)
            {
                ans1 = i*2;
                break;
            }
            if(w[i*2+1] == '1') cnt1++;
            if(cnt1 >= 5 - i)
            {
                ans1 = i*2+1;
                break;
            }
        }

        for(int i=0;i<5;i++)
        {
            if(l[i*2] == '1') cnt2++;
            if(cnt2 >= 6 - i)
            {
                ans2 = i*2;
                break;
            }
            if(l[i*2+1] == '1') cnt2--;
            if(cnt2 >= 5 - i)
            {
                ans2 = i*2+1;
                break;
            }
        }

        cout << min(min(ans1, ans2) + 1, 10) << "\n";
    }
}