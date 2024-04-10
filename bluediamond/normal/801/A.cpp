#include <bits/stdc++.h>

using namespace std;

#define open {
#define close }
#define bye return 0;
#define var int
#define str string
#define read(a) cin>>a;
#define print(a) cout<<a;
#define becomes =

str a;
var n;

var HowMany() open
    var ans becomes 0;
    for(var i=0;i+1<n;i becomes i+1) open
        if(a[i]=='V' && a[i+1]=='K')
            ans becomes ans+1;
    close
    return ans;
close

var main() open
    read(a);
    n becomes a.size();
    var ans becomes HowMany();
    for(var i=0;i<n;i becomes i+1) open
        if(a[i]=='V') a[i] becomes 'K';
        else a[i] becomes 'V';
        ans becomes max(ans,HowMany());
        if(a[i]=='V') a[i] becomes 'K';
        else a[i] becomes 'V';
    close
    print(ans);
    bye
close