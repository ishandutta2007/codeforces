#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s,ss;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> ss;
    if(n%2==1)
        printf("contest\n");
    else
        printf("home\n");
    return 0;
}