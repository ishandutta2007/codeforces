#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9;
struct el
{
    int ma, q=1, add=0;
};
el dot[sz*4];
void push(int nu)
{
    dot[nu*2].add+=dot[nu].add;
    dot[nu*2+1].add+=dot[nu].add;
    dot[nu].add=0;
}
void recalc(int nu)
{
    int lma=dot[nu*2].ma+dot[nu*2].add, rma=dot[nu*2+1].ma+dot[nu*2+1].add;

    if(lma>rma) dot[nu].ma=lma, dot[nu].q=dot[nu*2].q;
    else if(rma>lma) dot[nu].ma=rma, dot[nu].q=dot[nu*2+1].q;
    else dot[nu].ma=lma, dot[nu].q=dot[nu*2].q+dot[nu*2+1].q;
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu].ma=-inf, dot[nu].q=1;
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].add+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
pair <int, int> que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return {dot[nu].ma+dot[nu].add, dot[nu].q};
    else if(l>rg or r<lg) return {-inf, 1};
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        pair <int, int> lva=que(nu*2, l, mid), rva=que(nu*2+1, mid+1, r), re;
        if(lva.first == rva.first) re={lva.first, lva.second+rva.second};
        else re=max(lva, rva);
        recalc(nu);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], pr[n], gr=n-1;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]), ar[a]--, pr[a]=n;
    vector <int> st;
    st.push_back(n);
    long long an=0;
    build(1, 0, n-1);
    for(int a=n-1; a>=0; a--)
    {
        //cout<<a<<" ";
        while(st.size()>1 and ar[st.back()]<ar[a])
        {
            //cout<<1;
            lg=st.back();
            st.pop_back();
            rg=st.back()-1;
            va=ar[lg]-ar[a];
            //cout<<lg<<" "<<rg<<" "<<va<<"\n";
            cha(1, 0, n-1);
        }
        lg=a, rg=a, va=inf+a-ar[a];
        cha(1, 0, n-1);
        st.push_back(a);

        gr=min(gr, pr[ar[a]]-1), pr[ar[a]]=a;

        lg=a, rg=gr;
        pair <int, int> re=que(1, 0, n-1);
        if(re.first==a) an+=re.second;

        //cout<<re.first<<" ";
    }
    cout<<an;
}