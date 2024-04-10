#coding:utf8
n=raw_input()
m=raw_input()
n=sorted(n)
if(len(n)>1 and n[0]=='0'):
    tmp = n[0]
    n[0] = n[1]
    n[1] = tmp
n = ''.join(n)#''
if(n==m):
    print 'OK'
else:
    print'WRONG_ANSWER'