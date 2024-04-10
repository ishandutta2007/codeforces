#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll MD = 10007;
const double PI = 3.1415926535;
const int MAX_VALUE = (int)1e9;

//**************************************

int n;
string start;

set<string> a;

void bfs()
{
     vs q;
     q.push_back(start);
     string tmp;
     for (int ps=0;ps<q.size();ps++)
     {
         start = q[ps];
         int len = start.length();
         if (len==2)
         {
                               cout << "YES";
                               return;
         }
         if (len>=4 && (start[len-1]==start[len-3] || start[len-2]==start[len-4]))
         {
                    string tmp;
                    for (int i=0;i<len-4;i++)
                        tmp += start[i];
                    tmp += start[len-2];
                    tmp += start[len-1];
                    if (!a.count(tmp))
                    {
                                     a.insert(tmp);
                                     q.push_back(tmp);
                    }
         }
         if (len>=8 && (start[len-1]==start[len-7] || start[len-2]==start[len-8]))
         {
                    string tmp;
                    for (int i=0;i<len-8;i++)
                        tmp += start[i];
                    tmp += start[len-2];
                    tmp += start[len-1];
                    for (int i=len-6;i<len-2;i++)
                        tmp += start[i];
                    if (!a.count(tmp))
                    {
                                     a.insert(tmp);
                                     q.push_back(tmp);
                    }
         }
     }
     cout << "NO";
}

int main()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
        char c;
        cin >> c;
        start += c;
        cin >> c;
        start += c;
    }
    bfs();
    return 0;
}

//**************************************