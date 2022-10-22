main(n,m,s){
    scanf("%d%d%d",&n,&m,&s);
    printf("%lld\n",(long long)(ceil(1.*n/s)*ceil(1.*m/s)));
    return 0;
}