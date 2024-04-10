#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int A[26];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int n,i,d=0;
    int cnt = 0;
    string c;
    scanf("%d",&n);
    cin >> c;
    for(i=0; i<n; i++){
        if('a' <= c[i]){
            d = c[i]-'a';
        }
        else d = c[i]-'A';
        if(A[d] == 0) cnt++;
        A[d]++;
    }

    if(cnt == 26) printf("YES\n");
    else printf("NO\n");

    return 0;
}