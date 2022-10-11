import sys


def main():
    get_fr = {"0" : "",
              "1" : "",
              "2" : "2",
              "3" : "3",
              "4" : "322",
              "5" : "5",
              "6" : "53",
              "7" : "7",
              "8" : "7222",
              "9" : "7332"}

    n = input()
    st = input()
    answer = []
    for i in st:
        answer += list(get_fr[i])
    answer.sort(reverse = True)
    
    print("".join(answer))

main()