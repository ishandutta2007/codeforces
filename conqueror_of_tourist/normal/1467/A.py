for _ in[0]*int(input()):
 l=[(i+7)%10for i in range(int(input()))]
 l[0]=9
 print(''.join(map(str,l)))