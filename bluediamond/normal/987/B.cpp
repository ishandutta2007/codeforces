#include <bits/stdc++.h>

using namespace std;

double x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>y;
    if(x==y || (x==2 && y==4) || (x==4 && y==2)){
        cout<<"=\n";
        return 0;
    }
    if(log(x)/x>log(y)/y)
        cout<<">\n";
    else
        cout<<"<\n";

    return 0;
}
/**

**/