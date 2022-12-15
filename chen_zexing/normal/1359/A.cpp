#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        if(m<=n/k) printf("%d\n",m);
        else{
            m-=n/k;
            printf("%d\n",n/k-m/(k-1)-(m%(k-1)>0));
        }
    }
    return 0;
}