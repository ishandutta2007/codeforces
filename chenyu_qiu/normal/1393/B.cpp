
#include<bits/stdc++.h>
using namespace std;
int num[100000+10];
int main() {
    int n,a,q;
    cin>>n;
    int two ,four, six, eight;
    two = four = six = eight = 0;
    memset(num,0,sizeof(num));
    for (int i=0;i<n;i++){
        cin>>a;
        num[a] += 1;
        if(num[a]==2) two++;
        else if(num[a]==4) two--,four++;
        else if(num[a]==6) four--,six++;
        else if(num[a]==8) six--,eight++;
    }
    cin>>q;
    while(q--){
        int val;
        char c;
        cin>>c>>val;
        if(c=='+') {
            num[val] += 1;
            if(num[val]==2) two++;
            else if(num[val]==4) two--,four++;
            else if(num[val]==6) four--,six++;
            else if(num[val]==8) six--,eight++;
        }
        else {
            num[val] -= 1;
            if(num[val]==1) two--;
            else if(num[val]==3) two++,four--;
            else if(num[val]==5) four++,six--;
            else if(num[val]==7) six++,eight--;
 
        }
        if(eight>=1||six>=2||(six>=1&&(four!=0||two!=0))||four>=2||(four>=1&&two>=2)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}