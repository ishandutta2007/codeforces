#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int main(){
    int i,j,k,n,l,c,d,p,nl,np,an;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    an=min(k*l/nl/n,min(c*d/n,p/np/n));
    cout<<an<<endl;
    return 0;
}