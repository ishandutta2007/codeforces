    #include <bits/stdc++.h>
    using namespace std;
    #define pb push_back

    int hcf(int a,int b){
        if(a==0)return b;
        if(a>b)return hcf(b,a);
        return hcf(b%a,a);
    }
    int main(){
        ios_base::sync_with_stdio(false);
        int n,x,y,r=0;
        cin>>n>>x>>y;
        int u[n],v[n];
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b;
            b-=y;a-=x;
            if(a<0){a*=-1;b*=-1;}
            c=hcf(abs(a),abs(b));
            a/=c;b/=c;
            if(a==0)b=1;if(b==0)a=1;
            c=0;
            for(int i=0;i<r;i++)
                if(u[i]==a&&v[i]==b)c=1;
            if(c==0){u[r]=a;v[r]=b;r++;}
        }
        cout<<r;
    }