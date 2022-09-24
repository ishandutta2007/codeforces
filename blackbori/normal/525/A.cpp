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

int D[26];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int n,i,s=0;
    string c;

    scanf("%d",&n);
    cin >> c;
    for(i=0; i<n-1; i++){
        D[c[i*2]-'a']++;
        if(D[c[i*2+1]-'A']){
            D[c[i*2+1]-'A']--;
        }
        else s++;
    }

    printf("%d\n",s);

    return 0;
}