#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = 1e9;
const ll MAX_LL = 1e18;
const double eps = 1e-8;

string s,t;
int st[2*100000],ft[2*100000];
vector < vector<int> > a;
int ls,lt;

int main(){
    cin >> s >> t;
    ls = s.length();
    lt = t.length();
    st[lt-1]=-1;
    ft[0]=-1;
    for (int y=0,i=0;y<lt && i<ls;i++)
        if (s[i]==t[y]){
           st[y]=i;
           y++;
        }
    for (int y=lt-1,i=ls-1;i>=0 && y>=0;i--)
        if (s[i]==t[y]){
           ft[y]=i;
           y--;
        }
    if (st[lt-1]==-1 || ft[0]==-1){
       cout << "No" << endl;
       //system("pause");
       return 0;
    }
    a.resize(26);
    for (int i=0;i<ls;i++)
        a[s[i]-'a'].push_back(i);
    for (int c=0;c<26;c++){
        int y,i;
        for (y=0,i=0;y<a[c].size() && i<lt;i++)
            if ((t[i]-'a')==c)
               while (y<a[c].size() && a[c][y]>=st[i] && a[c][y]<=ft[i])y++;
        if (y<a[c].size()){
           cout << "No" << endl;
           //system("pause");
           return 0;
        }
    }    
    cout << "Yes" << endl;
    //system("pause");
    return 0;
}