#include<bits/stdc++.h>
using namespace std;
int hash1[26][200003],hash2[26][200003],p1=2463,mod1=10007,p2=1345,mod2=10009,pow1[200003],pow2[200003];
int main(){
    int n,q;
    string s;
    cin>>n>>q>>s;
    pow1[0]=1;
    pow2[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        pow1[i]=(pow1[i-1]*p1)%mod1;
        pow2[i]=(pow2[i-1]*p2)%mod2;
        for(int j=0;j<26;j++)
            hash1[j][i]=(hash1[j][i-1]*p1+(s[i-1]==char(j+'a'))+1)%mod1,
            hash2[j][i]=(hash2[j][i-1]*p2+(s[i-1]==char(j+'a'))+1)%mod2;
    }
    for(int i=0;i<q;i++){
        int a,b,len;
        scanf("%d %d %d",&a,&b,&len);
        vector<int>s1,s2,s3,s4;
        for(int j=0;j<26;j++){
            s1.push_back((hash1[j][a+len-1]-(hash1[j][a-1]*pow1[len]+mod1)%mod1+mod1)%mod1);
            s2.push_back((hash1[j][b+len-1]-(hash1[j][b-1]*pow1[len]+mod1)%mod1+mod1)%mod1);
            s3.push_back((hash2[j][a+len-1]-(hash2[j][a-1]*pow2[len]+mod2)%mod2+mod2)%mod2);
            s4.push_back((hash2[j][b+len-1]-(hash2[j][b-1]*pow2[len]+mod2)%mod2+mod2)%mod2);
            //cout<<hash1[j][a+len-1]<<'-'<<hash1[j][a-1]*pow1[len-1]
            //cout<<hash1[j][a+len-1]-hash1[j][a-1]*pow1[len]<<' ';
            //cout<<hash1[j][b+len-1]-hash1[j][b-1]*pow1[len]<<endl;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        sort(s3.begin(),s3.end());
        sort(s4.begin(),s4.end());
        if(s1==s2&&s3==s4)
            puts("YES");
        else
        	puts("NO");
        //cout<<endl;
	}
}