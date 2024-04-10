#include <bits/stdc++.h>
using namespace std;
string a[11],b[11];
int x,y,n;
int main(){
    a[2]="twenty"; a[3]="thirty"; a[4]="forty"; a[5]="fifty"; a[6]="sixty"; a[7]="seventy"; a[8]="eighty"; a[9]="ninety";
    b[0]="zero";
    b[1]="one"; b[2]="two"; b[3]="three"; b[4]="four"; b[5]="five"; b[6]="six"; b[7]="seven"; b[8]="eight"; b[9]="nine";
    cin>>n;
    x=n/10;
    y=n%10;
    if (n<=19 && n>=10) {
        if (n==10) cout<<"ten"; else if (n==11) cout<<"eleven";
        else if (n==12) cout<<"twelve"; else if (n==13) cout<<"thirteen";
        else if (n==14) cout<<"fourteen"; else if (n==15) cout<<"fifteen";
        else if (n==16) cout<<"sixteen"; else if (n==17) cout<<"seventeen";
        else if (n==18) cout<<"eighteen"; else cout<<"nineteen";
    } else {
    if (x>0)
    cout<<a[x];
    if (x>0 && y>0) cout<<"-";
    if (y>0) cout<<b[y];
    if (x==0 && y==0) cout<<"zero";
    }
}