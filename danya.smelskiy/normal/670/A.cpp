#include<cmath>
#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
int n,schet=0,scet=0,kolmin=0,kolmax=0,i;
cin>>n;
kolmin=(n/7)*2;
if (n%7==6) ++kolmin;
kolmax=2;
if (n==1) kolmax=1;
n=n-2;
kolmax=kolmax+((n/7)*2);
if (n%7==6) ++kolmax;
cout<<kolmin<<' '<<kolmax;
}