#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
bool check(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int t;
        for(int i=1;i<=100000;i++){
            if(!check(i)&&check(i+n-1))
            {
                t=i;
                break;
            }
        }
        for(int i=1;i<=n;i++,printf("\n"))
            for(int j=1;j<=n;j++){
                if(i==j) printf("%d ",t);
                else printf("1 ");
            }
    }
    return 0;
}