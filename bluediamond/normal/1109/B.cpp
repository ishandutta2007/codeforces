#include <bits/stdc++.h>

using namespace std;

bool IsPalindrome(string a)
{
        int n = (int) a.size();
        for (int i = 0; i < n - 1 - i; i++)
        {
                if (a[i] != a[n - 1 - i])
                {
                        return false;
                }
        }
        return true;
}

string s;
int n;

bool Wrong()
{
        if (n % 2 == 0)
        {
                for (int i = 1; i < n; i++)
                {
                        if (s[i] != s[0])
                        {
                                return false;
                        }
                }
                return true;
        }
        else
        {
                if (n == 1)
                {
                        return true;
                }
                else
                {
                        for (int i = 0; i < n; i++)
                        {
                                if (i != n / 2 && s[i] != s[0])
                                {
                                        return false;
                                }
                        }
                        return true;
                }
        }

}

bool InOne()
{
        for (int i = 0; i + 1 <= n - 1; i++)
        {
                string a;
                for (int j = i + 1; j <= n - 1; j++) a += s[j];
                for (int j = 0; j <= i; j++) a += s[j];
                if (a != s &&  IsPalindrome(a))
                {
                        return true;
                }
        }
        return false;
}


int main()
{
        cin >> s;
        n = (int) s.size();
        if (Wrong())
        {
                cout << "Impossible\n";
        }
        else
        {
                cout << 2 - (int) InOne() << "\n";
        }
        return 0;
}