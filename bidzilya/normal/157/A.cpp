#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int NMAX = 30;

int a[NMAX][NMAX];
int s1[NMAX],s2[NMAX];
int n;

int main(){
    cin >> n;
    for (int i=0;i<n;i++)
        s1[i]=s2[i]=0;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            cin >> a[i][j];
            s1[i] += a[i][j];
            s2[j] += a[i][j];
        }
    int ans =0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            ans += s2[j]>s1[i]?1:0;
    cout << ans;
    return 0;
}