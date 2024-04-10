#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n;
    cin>>n;
    unsigned max_ct=0;
    unsigned ct=0;
    bool pos[26];
    fill_n(pos,26,false);
    for(unsigned i=0;i<n;++i){
        char c;
        cin>>c;
        if(c>='a'&&c<='z'){
            if(!pos[c-'a']){
                ++ct;
                pos[c-'a']=true;
                max_ct=max(max_ct,ct);
            }
        }
        else{
            ct=0;
            fill_n(pos,26,false);
        }
    }
    cout<<max_ct<<endl;
}