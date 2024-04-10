    #include <bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define ll long long
    #define M 1000000007
    #define fr first
    #define sc second
    #define vc vector
    pair<ll, vc<ll> > s[100009];
    int main(){
        ios_base::sync_with_stdio(false);
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        int n,w=0,x=0,y=0,z=0;
        cin>>n;
        pair<int, int> a[n+5];
        for(int i=1;i<=n;i++){
            cin>>x;
            if(x>1){y++;w+=x;}
            else z++;
            a[i]={x,i};
        }
        w-=2*(y-1);
        if(z>w){cout<<"NO";return 0;}
        sort(a+1,a+n+1);
        cout<<"YES "<<(y-1+((z>2)?(2):(z)));
        cout<<"\n"<<(y-1+z)<<"\n";
        for(int i=1;i<y;i++){
            cout<<a[z+i].sc<<" "<<a[z+i+1].sc<<"\n";
            a[z+i+1].fr--;a[z+i].fr--;
        }
        int e=0;
        for(int i=1;i<=z;i++){
            cout<<a[i].sc<<" ";
            if(i!=2){
                if(a[n-e].fr==0)e++;
                a[n-e].fr--;
                cout<<a[n-e].sc<<"\n";
            }
            else {cout<<a[z+1].sc<<"\n";a[z+1].fr--;}
        }

    }