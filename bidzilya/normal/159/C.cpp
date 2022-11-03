#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxint (int)1e9
#define eps 1e-9
int k;
string s;

int del[2001][100];

int g[2001][26];

int find(char temp, int & v){
    int c = (int)temp - (int)'a';
    for (int i=1;i<=k;i++)
        if (g[i][c]>=v){
            g[i][c]--;
            return i;
        }
        else
            v -= g[i][c];
}

int main(){
    cin >>k;
    cin >> s;
    for (int i=1;i<=k;i++)
        for (int j=0;j<s.size();j++)
            del[i][j]=0;
    for (int j=0;j<26;j++)
        g[1][j]=0;
    for (int i=0;i<s.size();i++){
        int temp = (int)s[i]-(int)'a';
        g[1][temp]++;
    }
    for (int i=2;i<=k;i++)
        for (int j=0;j<26;j++)
            g[i][j]=g[1][j];
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        int tt,ind;
        char c;
        cin >> tt >> c;
        ind = find(c,tt);
        for (int j=0;j<s.size();j++)
            if (!del[ind][j]&&s[j]==c){
                tt--;
                if (tt==0){
                    del[ind][j]=1;
                    break;
                }
            }
    }
    for (int i=1;i<=k;i++)
        for (int j=0;j<s.size();j++)
            if (!del[i][j])
                cout << s[j];
    cout << endl;
	return 0;
}