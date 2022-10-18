#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
string x;
string ans;
int absl(int i){
    return (i<0?-i:i);
}
int main(){
    cin>>n>>x;
    int mid=n;
    for(int i=1;i<n;i++){
        if(x[i]!='0'){
            mid=min(mid,absl(i-n+i));
        }
    }
    ans=x;
    reverse(ans.begin(),ans.end());
    for(int i=1;i<n;i++){
        if(x[i]!='0'){
            if(absl(absl(i-n+i)-mid)<10){
                string a="",b="";
                for(int j=i-1;j>=0;j--){
                    a.push_back(x[j]);
                }
                for(int j=n-1;j>=i;j--){
                    b.push_back(x[j]);
                }
                string c="";
                int jw=0;
                for(int i=0;i<max(a.length(),b.length())+2;i++){
                    int v1=(i<a.length()?(a[i]-'0'):0);
                    int v2=(i<b.length()?(b[i]-'0'):0);
                    int ai=v1+v2+jw;
                    jw=ai/10;
                    c.push_back(ai%10+'0');
                }
                while(c[c.length()-1]=='0') c.pop_back();
                if(c.length()<ans.length()){
                    ans=c;
                }else if(c.length()==ans.length()){
                    for(int i=c.length()-1;i>=0;i--){
                        if(ans[i]>c[i]){
                            ans=c;
                            break;
                        }else if(c[i]>ans[i]){
                            break;
                        }
                    }
                }
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}