for i in range(int(input())):
    n,m,rb,cb,rd,cd=list(map(int,input().split()))
    print(min(rd-rb if rd>=rb else n-rb+n-rd,cd-cb if cd>=cb else m-cb+m-cd))