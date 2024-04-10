#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool isPalindrome(string S, int n)
{
    string T = S;
    reverse(T.begin(), T.end());
 
    for (int i = 0; i < n; i++)
    {
        if (S[i] != T[i])
            return false;
    }
 
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
 
    while (T--)
    {
        int n, cnt = 0;
        cin >> n;
 
        string S;
        cin >> S;
 
        for (char it : S)
                if (it == '0')
                    cnt++;
 
        if (isPalindrome(S, n))
        {
            
 
            if (cnt == 0)
                cout << "DRAW\n";
 
            if (cnt == 1)
                cout << "BOB\n";
 
            else if (cnt % 2)
                cout << "ALICE\n";
 
            else
                cout << "BOB\n";
        }
        else
        {
            bool f = true;
 
            if(cnt == 2 && n%2)
            {
                if(S[n/2] == '0')
                f = false;
            }
 
            if(f)
            cout<<"ALICE\n";
            else
            cout<<"DRAW\n";
        }
    }
    return 0;
}