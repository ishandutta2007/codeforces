#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int f[10];
int aux[10];

string s;
int n;

bool ok(int len)
{
        int xxx = len;
        for (int i = 0; i < 10; i++)
        {
                aux[i] = f[i];
        }
        int rem = n;
        while (len > 0)
        {
                rem--;
                int x = len % 10;
                len /= 10;
                aux[x]--;
                if (aux[x] < 0)
                {
                        return false;
                }
        }
        if (rem == xxx)
        {
                return true;
        }
        else
        {
                return false;
        }
}

void kek()
{
        for (int i = 0; i < 10; i++)
        {
                swap(f[i], aux[i]);
        }
}

string res;
bool first = true;

void upd(string x)
{
        //cout << " : " << x << "\n";
        if (first == true)
        {
                first = false;
                res = x;
        }
        else
        {
                res = min(res, x);
        }
}

string cur;

string add(bool now, bool finish, int cif)
{
       // cout << "\t\t\tadd = " << cif << "\n";
        if (now == true && finish == false)
        {
                cur += s;
        }
        for (int i = 0; i < f[cif]; i++)
        {
                cur += (char) (cif + '0');
        }
        if (now == true && finish == true)
        {
                cur += s;
        }
        return cur;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin >> s;
        n = (int) s.size();
        for (int i = 0; i < n; i++)
        {
                f[s[i] - '0']++;
        }
        cin >> s;
        for (int i = 0; i < (int) s.size(); i++)
        {
                f[s[i] - '0']--;
        }
        for (int l = 1; l <= n; l++)
        {

                if (ok(l) == true)
                {
                        kek();
                        if (s[0] != '0')
                        {
                                cur = s;
                                for (int i = 0; i < 10; i++)
                                {
                                        for (int j = 0; j < f[i]; j++)
                                        {
                                                cur += (char) (i + '0');
                                        }
                                }
                                upd(cur);
                        }
                        bool finish = false;
                        for (int i = 0; i < n; i++)
                        {
                                if (s[i] != s[0])
                                {
                                        if (s[i] > s[0])
                                        {
                                                finish = true;
                                        }
                                        break;
                                }
                        }
                       /** cout << "krr : \t";
                        for (int i = 0; i < 10; i++)
                        {
                                for (int j = 0; j < f[i]; j++)
                                {
                                        cout << i;
                                }
                        }
                        cout << "\n"; **/
                       /** cout << "\n\n";
                        cout << finish << "\n";
                        cout << "trump : " << f[3] << "\n"; **/
                      //  cout << l << "\n";
                        cur = "";
                        bool g = false;
                        for (int i = 1; i <= 9; i++)
                        {
                                if (f[i] == 0)
                                {
                                        continue;
                                }
                                f[i]--;
                                cur += (char) (i + '0');
                                g = true;
                                break;
                        }
                        if (g == false)
                        {
                                continue;
                        }
                //        cout << "now = " << cur << "\n";
                        for (int i = 0; i <= 9; i++)
                        {
                             //   cout << "trump : " << f[3] << "\n";
                                if (i == s[0] - '0')
                                {
                                        add(true, finish, i);
                                }
                                else
                                {
                                        add(false, finish, i);
                                }
                                f[i] = 0;
                        }
                    //    cout << "now = " << cur << "\n";
                        upd(cur);
                        kek();
                }
        }
        if (res.size() == 0)
        {
                res = "0";
        }
        cout << res << "\n";
        return 0;
}
/**


**/