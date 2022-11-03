#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int main(){
    char a[3][3];
    for (int i=0;i<3;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if (a[i][1]=='>')
            a[i][1]=1;
        else
            a[i][1]=0;
        if (a[i][2]<a[i][0]){
            char buf = a[i][0];
            a[i][0]=a[i][2];
            a[i][2]=buf;
            a[i][1]=(a[i][1]+1)%2;
        }
    }
    for (int i=0;i<2;i++)
        for (int j=i+1;j<3;j++)
            if (a[j][0]<a[i][0] || a[j][0]==a[i][0]&&a[j][2]<a[i][2]){
                char buf = a[j][0];a[j][0]=a[i][0];a[i][0]=buf;
                buf=a[j][1];a[j][1]=a[i][1];a[i][1]=buf;
                buf=a[j][2];a[j][2]=a[i][2];a[i][2]=buf;
            }

    if (a[0][1]==0 && a[1][1]==0 && a[2][1]==0)
        cout << "ABC";
    else
    if (a[0][1]==0 && a[1][1]==0 && a[2][1]==1)
        cout << "ACB";
    else
    if (a[0][1]==1 && a[1][1]==0 && a[2][1]==0)
        cout << "BAC";
    else
    if (a[0][1]==1 && a[1][1]==1 && a[2][1]==0)
        cout << "BCA";
    else
    if (a[0][1]==0 && a[1][1]==1 && a[2][1]==1)
        cout << "CAB";
    else
    if (a[0][1]==1 && a[1][1]==1 && a[2][1]==1)
        cout << "CBA";
    else
        cout << "Impossible";
    return 0;
}