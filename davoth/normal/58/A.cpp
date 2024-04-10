#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s,a="hello";
    cin>>s;
    while(a.size()&&s.size()){
        if(s[0]==a[0]){
            a.erase(a.begin());
        }
        s.erase(s.begin());
    }
    if(!a.size()) cout<<"YES";
    else cout<<"NO";
    return 0;
}