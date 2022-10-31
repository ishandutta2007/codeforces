function gcd(a,b)
{
    if (b)
        return gcd(b,a%b);
    return a;
}
var n=readline().split(" ").map(x=>parseInt(x))[0];
var numbers=readline().split(" ").map(x=>parseInt(x));
numbers.sort(function(a,b){return a-b});
var ans=numbers[1]-numbers[0];
for (i=1;i<n;i++)
    ans=gcd(ans,numbers[i]-numbers[i-1]);
print((numbers[n-1]-numbers[0])/ans+1-n);