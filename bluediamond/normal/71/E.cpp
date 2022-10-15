#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const string nw[] = {"","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
map <string, int> t;

int read()
{
        string s;
        cin >> s;
        return t[s];
}

int n, m;
int a[17], b[17];
int sum[1 << 17];
int len[1 << 17];
int pup[1 << 17];

vector <vector <int>> sol;

void print(bool ok)
{
        if (!ok)
        {
                cout << "NO\n";
                return;
        }
        cout << "YES\n";
        for (auto &rw : sol)
        {
                int sz = (int) rw.size();
                for (int j = 0; j + 1 < sz; j++)
                {
                        cout << nw[rw[j]];
                        if (j == sz - 2)
                                cout << "->";
                        else
                                cout << "+";
                }
                cout << nw[rw[sz - 1]] << "\n";
        }
}

int main()
{
      //  freopen("input", "r", stdin);
      //  freopen("output", "w", stdout);

        for (int i = 1; i <= 100; i++)
                t[nw[i]] = i;

        cin >> n >> m;
        for (int i = 0; i < n; i++)
                a[i] = read();
        for (int i = 0; i < m; i++)
                b[i] = read();
        for (int mk = 0; mk < (1 << n); mk++)
                for (int j = 0; (1 << j) <= mk; j++)
                        if (mk & (1 << j))
                                sum[mk] += a[j];
        len[0] = 0;
        for (int mk = 1; mk < (1 << n); mk++)
        {
                len[mk] = -1;
                for (int sub = mk; 1; sub = (sub - 1) & mk)
                {
                        int dif = mk - sub;
                        if (len[mk] == len[sub])
                                pup[mk] = sub;
                        if (len[sub] < 0) continue;
                        int need = b[len[sub]];
                        if (sum[dif] == need)
                        {
                                len[mk] = max(len[mk], len[sub] + 1);
                                if (len[sub] + 1 == len[mk])
                                        pup[mk] = sub;
                        }
                        if (sub == 0)
                                break;
                }
        }
        if (len[(1 << n) - 1] >= m)
        {
                int cur = (1 << n) - 1;
                int jj = m - 1;
                while (cur)
                {
                        int ant = pup[cur];
                        vector <int> addup;
                        int sub = cur - ant;
                        for (int j = 0; (1 << j) <= sub; j++)
                                if (sub & (1 << j))
                                        addup.push_back(a[j]);
                        addup.push_back(b[jj]);
                        sol.push_back(addup);
                        jj--;
                        cur = ant;
                }
                print(1);
        }
        else
                print(0);

}