#include <bits/stdc++.h>
using namespace std;



string s;
map<string,bool> used;
string ss,sss,ssss;
void recurs1(string x){
    if (used[x]) return ;
    if (x==sss+ssss) {
        cout<<"YES";
        exit(0);
    }
    used[x]=true;
    if (x[0]=='X') {
        swap(x[0],x[1]);
        recurs1(x);
        swap(x[0],x[1]);
        swap(x[0],x[2]);
        recurs1(x);
    } else if (x[1]=='X') {
        swap(x[0],x[1]);
        recurs1(x);
        swap(x[0],x[1]);
        swap(x[1],x[3]);
        recurs1(x);
    } else if (x[2]=='X') {
        swap(x[0],x[2]);
        recurs1(x);
        swap(x[0],x[2]);
        swap(x[2],x[3]);
        recurs1(x);
    } else if (x[3]=='X') {
        swap(x[2],x[3]);
        recurs1(x);
        swap(x[2],x[3]);
        swap(x[3],x[1]);
        recurs1(x);
    }
}
int main(){
    cin>>s>>ss>>sss>>ssss;
    recurs1(s+ss);
    cout<<"NO";
}