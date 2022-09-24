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

int n;
int D[100001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    string s;
    int i;

    cin >> s;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&D[i]);

    sort(D,D+n);
    int k=0;

    for(i=0; i<s.size()/2; i++){
        while(k<n && D[k]<=i+1)k++;
        if(k%2){
            char t=s[i];
            s[i]=s[s.size()-i-1];
            s[s.size()-i-1]=t;
        }
    }

    cout << s << endl;

    return 0;
}