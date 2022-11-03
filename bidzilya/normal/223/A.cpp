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

const int NMAX = 100000;

string s;
int a[NMAX];
char st[NMAX];
int ps[NMAX];
int sz = 0;
int n;

int main(){
    cin >> s;
    n = s.length();
    for (int i=0;i<n;i++)a[i] = -1;
    for (int i=0;i<n;i++)
        if (s[i]=='(' || s[i]=='['){
           st[sz] = s[i];
           ps[sz] = i;
           sz++;
        }else
        if (s[i]==')')
           if (sz>0 && st[sz-1]=='('){sz--;a[ps[sz]]=i;}
              else sz = 0;
        else
            if (sz>0 && st[sz-1]=='['){sz--;a[ps[sz]]=i;}
               else sz = 0;
    vector<int> l,r;
    for (int i=0;i<n;)
        if (a[i]==-1)i++;else{
           l.push_back(i);
           r.push_back(a[i]);
           i = a[i]+1;
        }
    int j=-1;
    for (int i=0;i<l.size();i++)
        if (j>=0 && l[i]==r[j]+1)
           r[j]=r[i];
        else{
           j++;
           l[j]=l[i];
           r[j]=r[i];
        }
    int left = 0, right = -1, ans = 0;
    for (int i=0;i<=j;i++){
        int ta = 0;
        for (int k=l[i];k<=r[i];k++)
            if (s[k]=='[')ta++;
        if (ta>ans){
           ans = ta;
           left = l[i];
           right = r[i];
        }
    }
    cout << ans << endl;
    for (int i=left;i<=right;i++)
        cout << s[i];
    cout << endl;        
    //system("pause");
    return 0;
}