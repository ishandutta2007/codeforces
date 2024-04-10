n = int(input())
line = []
for i in range(n):
    line += [list(map(int, input().split()))]
list_str = []
if line == [[0]]:
    print(1)
else:    
    for i in range(n):
        plus = False
        answer = 0
        for j in range(n):
            element = line[i][j]
            if element == 0:
                plus = True
            answer += element
        if plus:
            osob = answer
        else:
            list_str += [answer]
    if len(list_str) != 0 and min(list_str) != max(list_str):
        print(-1)
    else:
        chislo1 = min(list_str) - osob
        s1 = min(list_str)    
        list_str = []    
        for i in range(n):
            plus = False
            answer = 0
            for j in range(n):
                element = line[j][i]
                if element == 0:
                    plus = True
                answer += element
            if plus:
                osob = answer
            else:
                list_str += [answer]
        if len(list_str) == 0 or min(list_str) != max(list_str):
            print(-1)
        else:
            chislo2 = min(list_str) - osob
            s2 = min(list_str)    
            answer = 0
            plus = False
            for i in range(n):
                element = line[i][i]
                answer += element
                if element == 0:
                    plus = True
            if not plus:
                s3 = answer
                chislo3 = chislo2
            else:    
                s3 = s2
                chislo3 = s2 - answer
            answer = 0
            plus = False
            for i in range(n):
                element = line[i][n - i - 1]
                answer += element
                if element == 0:
                    plus = True
            if not plus:
                s4 = answer
                chislo4 = chislo2
            else:    
                chislo4 = s2 - answer 
                s4 = s2 
            if s1 == s2 and s1 == s3 and s1 == s4 and chislo1 == chislo2 and chislo1 == chislo3 and chislo1 == chislo4 and s1 > 0 and chislo1 > 0:
                print(chislo1)
            else:
                print(-1)