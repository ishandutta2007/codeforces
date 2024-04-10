s = input()
X = int(input())

if s.lower() == 'abc':
    works = X <= 1999
    
if s.lower() == 'arc':
    works = X <= 2799
    
if s.lower() == 'agc':
    works = X >= 1200


if works:
    print('YES')
else:
    print('NO')