#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int nimber(int x)
{
        if(x==1) return 1;
        if(x==2) return 1;
        if(x==3) return 2;
        if(x==4) return 2;
        if(x==5) return 2;
        if(x==6) return 3;
        if(x==7) return 3;
        if(x==8) return 3;
        if(x==9) return 3;
        if(x==10) return 4;
        if(x==11) return 4;
        if(x==12) return 4;
        if(x==13) return 4;
        if(x==14) return 4;
        if(x==15) return 5;
        if(x==16) return 5;
        if(x==17) return 5;
        if(x==18) return 5;
        if(x==19) return 5;
        if(x==20) return 5;
        if(x==21) return 6;
        if(x==22) return 6;
        if(x==23) return 6;
        if(x==24) return 6;
        if(x==25) return 6;
        if(x==26) return 6;
        if(x==27) return 6;
        if(x==28) return 7;
        if(x==29) return 7;
        if(x==30) return 7;
        if(x==31) return 7;
        if(x==32) return 7;
        if(x==33) return 7;
        if(x==34) return 7;
        if(x==35) return 7;
        if(x==36) return 8;
        if(x==37) return 8;
        if(x==38) return 8;
        if(x==39) return 8;
        if(x==40) return 8;
        if(x==41) return 8;
        if(x==42) return 8;
        if(x==43) return 8;
        if(x==44) return 8;
        if(x==45) return 9;
        if(x==46) return 9;
        if(x==47) return 9;
        if(x==48) return 9;
        if(x==49) return 9;
        if(x==50) return 9;
        if(x==51) return 9;
        if(x==52) return 9;
        if(x==53) return 9;
        if(x==54) return 9;
        if(x==55) return 10;
        if(x==56) return 10;
        if(x==57) return 10;
        if(x==58) return 10;
        if(x==59) return 10;
        if(x==60) return 10;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int res=0;
    while(n--)
    {
        int x;
        cin>>x;
        res^=nimber(x);
    }
    if(res==0)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}