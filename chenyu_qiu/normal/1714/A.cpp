#include <stdio.h>
 
int main() {
    int cases;
    scanf("%d", &cases);
    for (int i = 0;i<cases;i++) {
        int alarmCount, sleepHour,sleepMinute;
        scanf("%d %d %d", &alarmCount, &sleepHour, &sleepMinute);
        int alarmHour[alarmCount] = {0};
        int alarmMinute[alarmCount] = {0};
        int totalTime[alarmCount] ={0};
        for (int j = 0;j<alarmCount;j++) {
            scanf("%d %d", &alarmHour[j], &alarmMinute[j]);
        }
        for (int j = 0;j<alarmCount;j++) {
            if (alarmMinute[j]<sleepMinute) {
                alarmHour[j]--;
                alarmMinute[j]+=60;
            }
            if (alarmHour[j]<sleepHour) {
                alarmHour[j]+=24;
            }
            int totalSleepHour = alarmHour[j] - sleepHour;
            int totalSleepMinute = alarmMinute[j] - sleepMinute;
            totalTime[j] = totalSleepHour*60 + totalSleepMinute;
        }
        int trueTotalTime;
        for (int k = 0;k<alarmCount;k++) {
            if (k == 0) {
                trueTotalTime = totalTime[k];
            }
            else{
                if (trueTotalTime > totalTime[k]) {
                    trueTotalTime = totalTime[k];
                }
            }
        }
        int trueTotalHour = trueTotalTime/60;
        int trueTotalMinute = trueTotalTime%60;
        printf("%d %d\n", trueTotalHour, trueTotalMinute);
    }
    return 0;
}