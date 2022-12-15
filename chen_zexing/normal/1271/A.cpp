#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int e,f;
        cin>>e>>f;
        if(f>=e){
            int t1=min(b,min(c,d));
            int t2=min(a,d-t1);
            cout<<t1*f+t2*e<<endl;
        }
        else{
            int t1=min(a,d);
            int t2=min(b,min(c,d-t1));
            cout<<t1*e+t2*f<<endl;
        }
    }
    return 0;
}