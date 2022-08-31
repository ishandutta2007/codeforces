n, k = map(int, input().split())
string = input()
series = []
now = ""
for elem in string:
    if elem == "Y":
        if now:
            series.append(now)
        now = ""
    else:
        now += elem
if now:
    series.append(now)

answer = False
no_max = True
if not k:
    for elem in series:
        if elem.count('N'):
            answer = True
            
    print("YES" if not answer else "NO")
else:
    for elem in series:
        m = len(elem)
        for i in range(m - k + 1):
            if (not i or elem[i - 1] == '?') and ((i + k - 1) == m - 1 or elem[i + k] == '?'):
                answer = True
        
        counter = 0
        for letter in elem:
            if letter == 'N':
                counter += 1
                if counter > k:
                    no_max = False
            else:
                counter = 0
               
    print("YES" if answer and no_max else "NO")