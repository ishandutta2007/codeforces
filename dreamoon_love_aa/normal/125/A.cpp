#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int main(){
    int i,n;
    scanf("%d",&n);
    n++;
    n/=3;
    printf("%d %d\n",n/12,n%12);
    return 0;
}